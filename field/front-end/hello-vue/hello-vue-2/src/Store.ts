import Vuex from "vuex"
import Vue from "vue"
Vue.use(Vuex)
export default new Vuex.Store({
    state() {
        return {
            appname: "Book Management System 3!",
            books: [
                {
                    isbn: "213219217831273281712",
                    name: "枫叶与梦",
                    guidedPriceUSD: 5.99,
                    author: "Seymour Zhang"
                }
            ]
        }
    }
})