let read_int () = Scanf.bscanf Scanf.Scanning.stdib " %d " (fun x -> x) ;;
let read_double () = Scanf.bscanf Scanf.Scanning.stdib " %f " (fun x -> x) ;;

let tests = read_int () ;;

let set_times_for_farms c f x = 
  let time_for_farms = Array.make (truncate x + 1) 0. in
    for farms = 1 to truncate x do
      time_for_farms.(farms) <- time_for_farms.(farms - 1) +. c /. (2. +. f *. float (farms - 1))
    done ;
    time_for_farms ;;

let get_time f x farms time_for_farms = time_for_farms.(farms) +. x /. (2. +. f *. float farms) ;;

let solve c f x = 
  let time_for_farms = set_times_for_farms c f x in
    let rec get_min_time min_time farms =
      if farms > truncate x then min_time
      else get_min_time (min min_time (get_time f x farms time_for_farms)) (farms + 1)
    in get_min_time infinity 0 ;;

for test = 1 to tests do
  let c = read_double () and f = read_double () and x = read_double () 
  in Printf.printf "Case #%d: %.7f\n" test (solve c f x)
done ;;