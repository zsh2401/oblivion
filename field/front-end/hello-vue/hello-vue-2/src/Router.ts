import VueRouter from "vue-router";
import Vue from "vue"
import Home from "./Home.vue"
import AddNew from "./AddNew.vue"
import About from "./About.vue"
Vue.use(VueRouter)

export default new VueRouter({
    routes: [

        {
            path: "/",
            name: "Home",
            component: Home
        },

        {
            path: "/add-new",
            name: "AddNew",
            component: AddNew
        },

        {
            path: "/about",
            name: "About",
            component: About
        }
    ]
})