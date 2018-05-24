__ATPRERUN__.push(() => {
  console.log("[__ATPRERUN__] Prints from pre-loading stage ...");
});
// Push callback into execution queue
__ATPOSTRUN__.push(() => {
  console.log("[__ATPOSTRUN__] Prints from post-loading stage ...");
  Module.setStatus = function (status) {
    console.log("[Module.setStatus]", status);
  }
});

__ATINIT__.push(() => {
  console.log("[__ATINIT__] Prints from init stage ...");
});

__ATMAIN__.push(() => {
  console.log("[__ATMAIN__] Prints from main stage ...");
});

__ATEXIT__.push(() => {
  console.log("[__ATEXIT__] Prints from exit stage ...");
});

