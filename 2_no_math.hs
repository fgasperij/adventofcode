-- Day 1

main = do
    f <- readFile "./2_no_math.hs"
    putStrLn $ "Square feet of paper needed" ++ show (paper (lines f)) ++ "\n"
    putStrLn $ "Feets of ribbon needed " ++ show (ribbon (lines f)) ++ "\n"

paper :: [[Char]] -> Int
paper 
