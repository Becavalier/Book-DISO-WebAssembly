(module
 (type $iii (func (param i32 i32) (result i32)))
 (memory $0 0)
 (export "add" (func $assembly/module/add))
 (export "memory" (memory $0))
 (func $assembly/module/add (; 0 ;) (type $iii) (param $0 i32) (param $1 i32) (result i32)
  ;;@ assembly/module.ts:2:13
  (i32.add
   ;;@ assembly/module.ts:2:9
   (get_local $0)
   ;;@ assembly/module.ts:2:13
   (get_local $1)
  )
 )
)
