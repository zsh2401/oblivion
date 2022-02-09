<template>
    <div>
        <books :editable="true"></books>
    </div>
</template>
<script lang="ts">
import Vue from 'vue'
import Books from "./Books.vue"
export default Vue.extend({
    components: {
        Books
    }
})
</script>