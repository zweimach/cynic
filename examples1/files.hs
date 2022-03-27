module Main (main) where

import Control.Exception (
    Exception (displayException),
    SomeException,
    catch,
 )
import System.Directory (getHomeDirectory)
import System.Exit (exitFailure)
import System.FilePath (joinPath)
import System.IO (hPutStrLn, stderr)

main :: IO ()
main = do
    homeDir <- getHomeDirectory
    let filePath = joinPath [homeDir, ".bashrc"]
    result <- readFile filePath `catch` handleErr
    putStr result `catch` handleErr

handleErr :: SomeException -> IO a
handleErr e = do
    hPutStrLn stderr (displayException e)
    exitFailure
