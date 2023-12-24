import torch
from torch import nn
from sklearn.metrics import r2_score


# device = torch.device("mps")
# print("Device initialized.")
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
    X = torch.rand((10000, 2))
    x1 = X[:, 0]
    x2 = X[:, 1]
    y = x1 * x2
    return X, y


def train():
    model = MyMachine()
    model.train()
    X, y = get_dataset()
    NUM_EPOCHS = 10000
    optimizer = torch.optim.Adam(model.parameters(), lr=1e-2, weight_decay=1e-5)
    criterion = torch.nn.MSELoss(reduction='mean')

    for epoch in range(NUM_EPOCHS):
        optimizer.zero_grad()
        y_pred = model(X)
        y_pred = y_pred.reshape(10000)
        loss = criterion(y_pred, y)
        loss.backward()
        optimizer.step()
        print(f'Epoch:{epoch}, Loss:{loss.item()}')
    torch.save(model.state_dict(), 'model.h5')


def test():
    model = MyMachine()
    model.load_state_dict(torch.load("model.h5"))
    model.eval()
    X, y = get_dataset()
    print(X.dtype)
    with torch.no_grad():
        y_pred = model(X)
        # print(f"X data : {X}")
        # print(f"X pred : {y_pred}")
        print(r2_score(y, y_pred))


def pred():
    model = MyMachine()
    model.load_state_dict(torch.load("model.h5"))
    model.eval()

    def do_pred():
        x1, t1, z1 = to_safe_area(float(input("x1")))
        x2, t2, z2 = to_safe_area(float(input("x2")))
        X = torch.tensor([[x1, x2]])
        Y = model(X)
        print(f"Result is {Y[0] * z1 * z2}")

    while True:
        do_pred()


def to_safe_area(x):
    if x < 1:
        return x, 1, 1
    else:
        x, t, z = to_safe_area(x * 0.1)
        return x, t * 0.1, z * 10


train()
# test()
pred()
# print(to_safe_area(10))

#%%
