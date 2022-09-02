let pr result = List.iter (fun (p, q) -> Printf.printf "%d %d\n" p q) result

let run (module M : Union_find.S) (n : int) (gen : unit -> int * int) :
    float * int * (int * int) list =
  let start = Unix.gettimeofday () in
  let m = ref 0 in
  let i = ref 0 in
  let res = Array.init 100_000 (fun _ -> (0, 0)) in
  let rec run_aux () =
    if !i = n - 1 then ()
    else
      let _ = incr m in
      let pair = gen () in
      if M.find pair then run_aux ()
      else (
        res.(!i) <- pair;
        incr i;
        run_aux ())
  in
  let _ = run_aux () in
  let now = Unix.gettimeofday () in
  (now -. start, !m, Array.to_list res)

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

let input_all ch =
  let out = Array.init 100_000 (fun _ -> (0, 0)) in
  let i = ref 0 in
  let rec aux () =
    match In_channel.input_line ch with
    | Some line -> (
        try
          let pair = Scanf.sscanf line "%d %d" (fun p q -> (p, q)) in
          out.(!i) <- pair;
          incr i;
          aux ()
        with _ -> failwith "failed to parse")
    | None -> ()
  in
  aux ();
  out

let summarise results : unit =
  List.iter
    (fun (elapsed, m, _) -> Printf.printf "%f M: %d\n" elapsed m)
    results
