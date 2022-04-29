{-# LANGUAGE OverloadedStrings #-}

module Main (main) where

import Data.Foldable (Foldable (..))
import Data.Sequence (Seq, (><), (|>))
import qualified Data.Sequence as Seq
import Data.Text (Text)
import qualified Data.Text as Text
import qualified Data.Text.IO as Text
import Prelude hiding (print)

main :: IO ()
main = do
    let parsed = parse "ABCCBA"
    let printed = print parsed
    Text.putStrLn printed

data Morse = Dot | Dash
    deriving (Show, Eq)

parse :: Text -> [Morse]
parse = toList . Text.foldl' go Seq.empty
  where
    go :: Seq Morse -> Char -> Seq Morse
    go acc str =
        case str of
            'A' -> (acc |> Dot |> Dash) >< charDelim
            'B' -> (acc |> Dash |> Dot |> Dot |> Dot) >< charDelim
            'C' -> (acc |> Dash |> Dot |> Dash |> Dot) >< charDelim
            _ -> acc

    charDelim = Seq.fromList [Dot, Dot, Dot]

print :: [Morse] -> Text
print = Text.concat . reverse . go []
  where
    go :: [Text] -> [Morse] -> [Text]
    go acc s = case s of
        Dot : Dot : Dot : xs -> go acc xs
        Dot : Dash : xs -> go ("A" : acc) xs
        Dash : Dot : Dot : Dot : xs -> go ("B" : acc) xs
        Dash : Dot : Dash : Dot : xs -> go ("C" : acc) xs
        _ -> acc
