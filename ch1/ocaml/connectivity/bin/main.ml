let () =
  let rec read () =
    match In_channel.input_line stdin with
    | Some line ->
        print_endline line;
        read ()
    | None -> ()
  in
  read ()
