<template>
    <div>
        <div v-if="editable">
            <el-button-group>
                <el-button @click="onAddNew">New</el-button>
                <el-button :disabled="selected.length === 0" @click="onDeleting">Remove Selected</el-button>
            </el-button-group>
        </div>
        <el-table
            @row-click="onRowDoubleClicked"
            :data="this.$store.state.books"
            stripe
            @selection-change="onSelectionChanged"
        >
            <el-table-column type="selection" width="55"></el-table-column>
            <el-table-column prop="name" label="Name" />
            <el-table-column prop="author" label="Author" />
            <el-table-column prop="guidedPriceUSD" label="$Price" />
        </el-table>
    </div>
</template>

<script lang="ts">
import Vue from 'vue'
import BookDetails from './BookDetails.vue'
export default Vue.extend({
    props: ['editable'],
    data() {
        return {
            selected: []
        }
    },
    components: {
        BookDetails
    },
    methods: {

        onAddNew() {
            this.$router.push("/add-new")
        },

        onRowDoubleClicked(r: any,) {
            this.$msgbox({
                title: "Details",
                message: this.$createElement('book-details', {
                    props: {
                        book: r
                    }
                })
            })
        },

        onDeleting() {
            this.$store.state.books = this.$store.state.books.filter(book =>
                this.selected.findIndex(_book => _book.isbn === book.isbn) === -1
            )

        },
        onSelectionChanged(val: []) {
            this.selected = val
        }
    }
})
</script>
<style scoped>
</style>