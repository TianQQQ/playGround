<template>
    <div>
        <p>page limit is {{ limit }}; total page num is {{ totalPageNum }}; all pages are {{ allPages }} </p>
        <table class="ui celled striped table">
            <thead>
            <tr>
                <th>Update at. </th>
            </tr>
            </thead>
            <tbody>
            <tr v-for="item in allPages[curPageNum]">
                <td> {{ item.id}} --> {{ item.text }}</td>
            </tr>
            </tbody>
        </table>
        <button id="pre" @click="movedown"> pre </button>
        <button id="next" @click="moveup"> next </button>

    </div>

</template>

<script>
    export default {
        props: ['item', 'limit', 'task'],  // accept from html (template)


        data  () {
            return {
                curPageNum: 0
            }
        },
        computed: {
            totalPageNum() { return  Math.ceil( this.tasks.length / this.limit ) },
            allPages() {
                var cur = {}
                var i = 0
                for (i == 0; i < this.totalPageNum; i++)
                    cur[i] = this.tasks.slice(i * this.limit, (i+1) * this.limit)
                return cur
            },

        },
        methods: {
            moveup() {
                if (this.curPageNum + 1 < this.totalPageNum)
                    this.curPageNum += 1
            },
            movedown() {
                if (this.curPageNum - 1 >= 0)
                    this.curPageNum -= 1
            },
        }
    }

    //await this.count = TaskService.count({'location': this.checkedPlace})
</script>