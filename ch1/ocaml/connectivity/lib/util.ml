let pr result = List.iter (fun (p, q) -> Printf.printf "%d %d\n" p q) result

let run (module M : Union_find.S) (n : int) (gen : unit -> int * int) :
    float * int * (int * int) list =
  let start = Unix.gettimeofday () in
  let m = ref 0 in
  let rec run_aux res =
    if List.length res = n - 1 then res
    else
      let _ = incr m in
      let pair = gen () in
      if M.find pair then run_aux res else run_aux (pair :: res)
  in
  let res = run_aux [] in
  let now = Unix.gettimeofday () in
  (now -. start, !m, List.rev res)

let all_equals pairs : bool =
  let two_equals (left : (int * int) list) (right : (int * int) list) : bool =
    if List.length left <> List.length right then false
    else List.for_all2 (fun (p1, q1) (p2, q2) -> p1 = p2 && q1 = q2) left right
  in
  let rec all_equals_aux pairs =
    match pairs with
    | [] | _ :: [] -> true
    | left :: right :: rest ->
        if two_equals left right then all_equals_aux (right :: rest) else false
  in
  all_equals_aux pairs

let rec input_all ch pairs : (int * int) list =
  match In_channel.input_line ch with
  | Some line -> (
      try
        let pair = Scanf.sscanf line "%d %d" (fun p q -> (p, q)) in
        input_all ch (pair :: pairs)
      with _ -> failwith "failed to parse")
  | None -> List.rev pairs

let summarise results : unit =
  List.iter
    (fun (elapsed, m, _) -> Printf.printf "%f M: %d\n" elapsed m)
    results
