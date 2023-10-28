import torch
from torch import nn
from sklearn.metrics import r2_score

# device = torch.device("mps")
# print("Device initialized.")

TRAIN_DATA_LEN = 10_000


class MyMachine(nn.Module):
    def __init__(self):
        super().__init__()
        self.fc = nn.Sequential(
            nn.Linear(2, 5),
            nn.ReLU(),
            nn.Linear(5, 1)
        )

    def forward(self, x):
        x = self.fc(x)
        return x


def get_dataset():
    X = torch.rand((TRAIN_DATA_LEN, 2))
    # y = torch.tensor()
    y_arr = []

    for i in range(0, TRAIN_DATA_LEN):
        # pass
        [x, y] = X[i]
        if x > 0 and y > 0:
            y_arr = 1.0
        elif x < 0 and y > 0:
            y_arr = 2.0
        elif x < 0 and y < 0:
            y_arr = 3.0
        else:
            y_arr = 4.0

    return X, torch.tensor(y_arr)


def train():
    model = MyMachine()
    model.train()
    X, y = get_dataset()
    NUM_EPOCHS = TRAIN_DATA_LEN
    optimizer = torch.optim.Adam(model.parameters(), lr=1e-2, weight_decay=1e-5)
    criterion = torch.nn.MSELoss(reduction='mean')

    for epoch in range(NUM_EPOCHS):
        optimizer.zero_grad()
        y_pred = model(X)
        y_pred = y_pred.reshape(TRAIN_DATA_LEN)
        loss = criterion(y_pred, y)
        loss.backward()
        optimizer.step()
        print(f'Epoch:{epoch}, Loss:{loss.item()}')
    torch.save(model.state_dict(), 'model.h5')


# def test():
#     model = MyMachine()
#     model.load_state_dict(torch.load("model.h5"))
#     model.eval()
#     X, y = get_dataset()
#     print(X.dtype)
#     with torch.no_grad():
#         y_pred = model(X)
#         # print(f"X data : {X}")
#         # print(f"X pred : {y_pred}")
#         print(r2_score(y, y_pred))

def pred():
    model = MyMachine()
    model.load_state_dict(torch.load("model.h5"))
    model.eval()
    X = torch.tensor([[-1.0,-1.0]])
    # print(X.dtype)
    print(model(X))


train()
# test()
pred()
