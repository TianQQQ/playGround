<template>
    <div>
        <h1>{{ msg }} </h1>
        <button @click="reverseMsg"> reverse message</button>
        <input v-model="msg">
        <span :title="msg"> put and suspend to see the content </span>
        <p v-if="seen"> now you see me</p>
        <ol>
            <li v-for="a in lists">
                {{ a.text }}
            </li>
        </ol>
        <hahaha></hahaha>
        <br>
        <lay_page :limit=5 :task="groceryList"></lay_page>

    </div>
</template>

<script>

    const NotFound = { template: '<p>Page not found</p>' }
    const Home = { template: '<p>home page</p>' }
    const About = { template: '<p>about page</p>' }
    const routes = {
        '/': Home,
        '/about': About
    }
    export default {
        data () {
            return{
                status: 'aaaaaaa',
                msg: 'Welcome to Your Vue.js App',
                seen: true,
                lists: [{text: 'aaa'}, {text: 'bbb'}, {text: 'ccc'}],
                groceryList: [
                    { id: 0, text: '111' },
                    { id: 1, text: '222' },
                    { id: 2, text: '333' },
                    { id: 3, text: '111' },
                    { id: 4, text: '222' },
                    { id: 5, text: '111' },
                    { id: 6, text: '222' },
                    { id: 7, text: '111' },
                    { id: 8, text: '222' },
                    { id: 9, text: '111' },
                    { id: 10, text: '222' },
                    { id: 11, text: '111' },
                    { id: 12, text: '222' },
                ],
                currentRoute: window.location.pathname,
            }
        },
        methods: {
            changeStatus(){
                this.status = 'vvvvvvv';
            },
            reverseMsg() {
                this.msg = this.msg.split('').reverse('').join('')
            }
        },
        computed: {
            ViewComponent () {
                return routes[this.currentRoute] || NotFound
            }
        },
        render (h) { return h(this.ViewComponent) }
    }

</script>