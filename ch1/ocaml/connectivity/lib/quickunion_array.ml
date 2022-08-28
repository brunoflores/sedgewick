(* Each object points to another object in the same set, in a structure with no
   cycles.

   To determine whether two objects are in the same set, we follow pointers for
   each until we reach an object that points to itself.

   The objects are in the same set if and only if this process leads them to the
   same object.

   If they are not in the same set, we wind up at different objects (which point
   to themselves).

   To perform the union, we just link one to the other. *)

let seen : int array = Array.init 100_000 (fun i -> i)

let find (p, q) : bool =
  let rec find_aux (x : int) : int =
    let peek = seen.(x) in
    if peek = x then x else find_aux peek
  in
  let i = find_aux p in
  let j = find_aux q in
  if i = j then true
  else (
    seen.(i) <- j;
    false)
