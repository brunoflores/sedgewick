let seen : int array = Array.init 10_000 (fun i -> i)

let find (pair : int * int) : (int * int) option =
  let p, q = pair in
  if seen.(p) = seen.(q) then None else Some pair

let union (p, q) : unit =
  let seen_p = seen.(p) in
  let seen_q = seen.(q) in
  Array.iteri
    (fun i seen_item -> if seen_item = seen_p then seen.(i) <- seen_q)
    seen
