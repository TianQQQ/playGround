import Vue from 'vue'
import App from './App.vue'
import Home from './Home.vue'
import Lay_page from './Lay_page.vue'
import VueRouter from 'vue-router'


Vue.component('hahaha', Home);
Vue.component('lay_page', Lay_page);
Vue.use(VueRouter);

new Vue({
  el: '#app',
  render: h => h(App)
});
