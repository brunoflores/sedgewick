(* Each object points to another object in the same set, in a structure with no
   cycles.

   To determine whether two objects are in the same set, we follow pointers for
   each until we reach an object that points to itself.

   The objects are in the same set if and only if this process leads them to the
   same object.

   If they are not in the same set, we wind up at different objects (which point
   to themselves).

   To perform the union, we just link one to the other. *)

let n = 100_000
let seen : int array = Array.init n (fun i -> i)
let size : int array = Array.init n (fun _ -> 1)

let find (p, q) : bool =
  let rec find_aux (x : int) i : int * int =
    let peek = seen.(x) in
    if peek = x then (x, i) else find_aux peek (i + 1)
  in
  let i, dist_i = find_aux p 0 in
  let j, dist_j = find_aux q 0 in
  if i = j then true
  else (
    size.(i) <- dist_i + dist_j;
    seen.(i) <- j;
    false)

let average_distance () = Array.fold_left ( + ) 0 size / n
