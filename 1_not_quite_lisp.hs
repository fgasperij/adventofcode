-- Day 1

main = do
    s <- getLine
    putStrLn $ "Ends up in floor " ++ show (santas_floor s) ++ "\n"
    putStrLn $ "It reaches the basement in position " ++ show (first_basement s) ++ "\n"

santas_floor :: [Char] -> Int
santas_floor = foldr update_floor 0

update_floor :: Char -> Int -> Int
update_floor '(' r = r + 1
update_floor ')' r = r - 1

-- with foldr?
first_basement :: [Char] -> Int
first_basement cs  = first_basement_aux cs 0 1

first_basement_aux :: [Char] -> Int -> Int -> Int
first_basement_aux [] _ _ = -1
first_basement_aux (')':_) 0 i = i
first_basement_aux (')':xs) f i = first_basement_aux xs (f-1) (i+1)
first_basement_aux ('(':xs) f i = first_basement_aux xs (f+1) (i+1)
