<script lang="ts">
  let count: number = 0;
  let nums: number[] = [];
  const increment = () => {
    nums.push(1);
    nums = nums
    count += 1;
  };
</script>

<button class="a" on:click={increment}>
  count is {count} 
</button>

{#each nums as num}
  <h1>{num}</h1>
{/each}

<style lang="scss">
  .a {
    color: green;
  }
</style>
