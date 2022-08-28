let _pr result = List.iter (fun (p, q) -> Printf.printf "%d %d\n" p q) result

let run (module M : Connectivity.Union_find.S) (n : int)
    (gen : unit -> int * int) : float * (int * int) list =
  let start = Unix.gettimeofday () in
  let rec run_aux res =
    if List.length res = n - 1 then res
    else
      let pair = gen () in
      if M.find pair then run_aux res else run_aux (pair :: res)
  in
  let res = run_aux [] in
  let now = Unix.gettimeofday () in
  (now -. start, List.rev res)

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
  List.iter (fun (elapsed, _) -> Printf.printf "%f\n" elapsed) results

let () =
  let input = input_all stdin [] in
  let n = 10 in
  let gen () =
    let i = ref 0 in
    fun () ->
      try
        let v = List.nth input !i in
        incr i;
        v
      with _ -> failwith @@ Format.sprintf "out of input: %d" !i
  in
  let results_timed =
    [
      run (module Connectivity.Quickfind_array) n (gen ());
      run (module Connectivity.Quickunion_array) n (gen ());
      run (module Connectivity.Quickunion_weighted_array) n (gen ());
    ]
  in
  let results = List.map (fun (_, pair) -> pair) results_timed in
  match results with
  | [] -> ()
  | _result :: _ ->
      if all_equals results then summarise results_timed
      else print_endline "failed"
