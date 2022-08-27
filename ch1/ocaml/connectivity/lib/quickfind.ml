let n = 10_000
let seen : int array = Array.init n (fun i -> i)

let find (pair : int * int) : (int * int) option =
  let p, q = pair in
  if seen.(p) = seen.(q) then None else Some pair

let union (p, q) : unit =
  let t = seen.(p) in
  for i = 0 to n - 1 do
    if seen.(i) = t then seen.(i) <- seen.(q)
  done
