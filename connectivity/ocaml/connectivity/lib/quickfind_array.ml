let seen : int array = Array.init 100_000 (fun i -> i)

let union (p, q) : unit =
  let seen_p = seen.(p) in
  let seen_q = seen.(q) in
  Array.iteri
    (fun i seen_item -> if seen_item = seen_p then seen.(i) <- seen_q)
    seen

let find (pair : int * int) : bool =
  let p, q = pair in
  if seen.(p) = seen.(q) then true
  else (
    union pair;
    false)
