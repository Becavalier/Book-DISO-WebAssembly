__ATPOSTRUN__.push(() => {
  console.log(Module['OldStyle']['ONE'].value);  // 0
  console.log(Module['NewStyle']['TWO'].value);  // 1
});
