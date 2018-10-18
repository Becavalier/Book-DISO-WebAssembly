(module
  (import "env" "memory" (memory (;0;) 1 1 shared))
  (export "memory" (memory 0))
  (export "tryLockMutex" (func $tryLockMutex))
  (export "lockMutex" (func $lockMutex))
  (export "unlockMutex" (func $unlockMutex))
  (func $tryLockMutex (param $mutexAddr i32) (result i32)
    (i32.eqz
      (i32.atomic.rmw.cmpxchg
        (get_local $mutexAddr)
        (i32.const 0)
        (i32.const 1))))
  (func $lockMutex (param $mutexAddr i32)
    (block $done
      (loop $retry
        (br_if $done
          (call $tryLockMutex
            (get_local $mutexAddr)))
        (drop
          (i32.atomic.wait
            (get_local $mutexAddr)
            (i32.const 1)
            (i64.const 1000)))
        (br $retry))))
  (func $unlockMutex (param $mutexAddr i32)
    (i32.atomic.store
      (get_local $mutexAddr)
      (i32.const 0))
    (drop
      (atomic.wake
        (get_local $mutexAddr)
        (i32.const 1))))
  (type (;0;) (func (param i32) (result i32)))
  (type (;1;) (func (param i32))))