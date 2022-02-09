<template>
    <div>
        <h1>Add New Book</h1>

        <el-form :model="form" ref="form" label-width="120px">
            <el-form-item label="ISBN">
                <el-input v-model="form.isbn"></el-input>
            </el-form-item>

            <el-form-item label="Book Name">
                <el-input v-model="form.name"></el-input>
            </el-form-item>

            <el-form-item label="Author">
                <el-input v-model="form.author"></el-input>
            </el-form-item>

            <el-form-item label="Guided Price$">
                <el-input v-model="form.guidedPriceUSD"></el-input>
            </el-form-item>

            <el-form-item>
                <el-button type="primary" :disabled="this.form.isbn == ''" @click="onSubmit">Save</el-button>
                <el-button @click="$router.go(-1)">Cancel</el-button>
            </el-form-item>
        </el-form>
    </div>
</template>
<script lang="ts">
import Vue from 'vue'
export default Vue.extend({
    data() {
        return {
            form: {
                isbn: '',
                name: 'Unknown Book',
                guidedPriceUSD: 0,
                author: "Anonymous"
            }
        }
    },
    methods: {
        onSubmit() {
            this.$store.state.books.push(this.form)
            this.$alert("New books has been saved to current system.", "OK", {
                confirmButtonText: "ok",
                callback: () => {
                    this.$router.go(-1)
                }
            })
        }
    }
})
</script>