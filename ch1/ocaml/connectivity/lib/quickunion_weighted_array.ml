let n = 100_000
let seen : int array = Array.init n (fun i -> i)

(* For each object with [seen.(i) = i], [size.(i)] keeps the number of nodes
   in the associated tree. *)
let size : int array = Array.init n (fun _ -> 1)

let find (p, q) : bool =
  let rec find_aux (x : int) : int =
    let peek = seen.(x) in
    if peek = x then x else find_aux peek
  in
  let i = find_aux p in
  let j = find_aux q in
  if i = j then true
  else (
    if size.(i) < size.(j) then (
      seen.(i) <- j;
      size.(j) <- size.(j) + size.(i))
    else (
      seen.(j) <- i;
      size.(i) <- size.(i) + size.(j));
    false)

let average_distance () = Array.fold_left ( + ) 0 size / n
