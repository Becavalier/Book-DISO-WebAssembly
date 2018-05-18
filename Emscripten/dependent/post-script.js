__ATPOSTRUN__.push(() => {
  // -s 'EXTRA_EXPORTED_RUNTIME_METHODS=["ccall"]'
  Module.ccall('echo', null, ['number'], [10]);

  // Module['asm']['_echo'](100);
});

