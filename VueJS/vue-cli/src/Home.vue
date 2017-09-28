<template>
    <div>
        <p>Server Status: {{ status }}</p>
        <hr>
        <button @click="changeStatus"> Change</button>
    </div>

</template>

<script>
    export default {
        props(){
            return ['item']
        },  // accept from html
        template(){
            '<li> {{ item.id }} --> {{ item.text}} </li>'
        },
        data () {
            return{
                status: 'aaaaaaa'
            }
        },
        methods: {
            changeStatus(){
                this.status = 'vvvvvvv';
            }
        }

    }

</script>