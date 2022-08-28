let () =
  let n = 100_000 in
  let _ns = Array.init n (fun i -> i) in
  let ms = Array.init (n - 1) (fun i -> (i, i + 1)) in
  Array.iter (fun (p, q) -> Printf.printf "%d %d\n" p q) ms
