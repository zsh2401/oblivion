<template>
    <button @click="onClick">Count: {{ count }}</button>
</template>
<script lang="ts">
import Vue from "vue"
export default Vue.extend({
    data() {
        return {
            count: 1
        }
    },
    methods: {
        onClick() {
            this.count++;
        }
    }
})
</script>