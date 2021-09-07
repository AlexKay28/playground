package main

import (  
    "mlpack.org/v1/mlpack"
    "fmt"
)

func main() {
  mlpack.DownloadFile(
      "https://www.mlpack.org/datasets/covertype-small.data.csv.gz",
      "data.csv.gz"
  )
  mlpack.DownloadFile(
      "https://www.mlpack.org/datasets/covertype-small.labels.csv.gz",
      "labels.csv.gz
  )
  
  mlpack.UnZip("data.csv.gz", "data.csv")
  mlpack.UnZIp("labels.csv.gz", "labels.csv")
  
  dataset, _ := mlpack.load("data.csv")
  labels, _  := mlpack.load("labels.csv")
  
  params := mlpack.PreprocessSplitOptions()
  params.InputLabels = labels
  params.TestRatio   = 0.3
  params.Verbose     = true
  
  X_test, y_test, X_train, y_train := 
      mlpack.PreprocessSplit(dataset, params)
  
  rf_params := mlpack.RandomForestOptions()
  rf_params.NumTrees = 10
  rf_params.MinimumLeafSize = 3
  rf_params.PrintTrainingAccuracy = true
  rf_params.Training = X_train
  rf_params.Labels = y_train
  rf_params.Verbose = true
  
  rf_model, _, _ := mlpack.RandomForest(rf_params)
  
  rf_params_2 := mlpack.RandomForestOptions()
  rf_params_2.Test = X_test
  rf_params_2.InputModel = &rf_model
  rf_params_2.Verbose = true
  
  _, predictions, _ := mlpack.RandomForest(rf_params_2)
  
  rows, _ := predictions.Dims()
  var sum int = 0
  for i:=0; i < rows; i ++ {
    if (predictions.At(i, 0) == test_labels.At(i, 0)) {
      sum = sum + 1
    }
  }
  fmt.Print("Correct answers rate: ", sum, "/", rows)
  fmt.Print("Acc: ", (float64(sum)/float64(rows)) * 100, "%")
  
}
