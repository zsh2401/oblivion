<template>
    <div>
        <h3>ISBN: {{ book.isbn }}</h3>
    </div>
</template>
<script lang="ts">
import Vue from 'vue'
export default Vue.extend({
    props: ['book']
})
</script>