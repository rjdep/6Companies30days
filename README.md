# Image-Based Weather Classification

This project implements a Convolutional Neural Network (CNN) to classify weather conditions from images into four categories. The model is built using PyTorch and trained on a labeled dataset of weather images.

## Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Dataset](#dataset)
- [Model Architecture](#model-architecture)
- [Training and Evaluation](#training-and-evaluation)
- [Results](#results)

---

## Overview

The goal of this project is to classify images of weather conditions (e.g., sunny, cloudy, rainy, snowy) using a deep learning model. The model uses convolutional layers to extract spatial features and fully connected layers to perform classification.

---

## Features

- **Dynamic Fully Connected Layers**: Automatically adjusts to input size.
- **Regularization**: Dropout layer to prevent overfitting.
- **Custom Data Augmentation**: Supports resizing, normalization, and shuffling.

---

## Dataset

The dataset consists of weather images organized into subdirectories, where each subdirectory represents a class. Ensure your data follows the structure:

---

## Model Architecture

- **Convolutional Layers**: Two layers with kernel size 3x3 and ReLU activation.
- **Pooling Layer**: Max-pooling reduces dimensions.
- **Fully Connected Layers**: Two layers with dropout regularization.
- **Dynamic Layer Initialization**: fc1 dynamically adapts to flattened output size.

---

## Training and Evaluation

- **Training:**

- Optimizer: Adam
- Loss: CrossEntropyLoss
- Batch size: 32
- Epochs: 15
- Learning rate: 0.001

- **Evaluation:**

- Computes accuracy on the test set.

  ---

- **Results**
  
- After training for 15 epochs, the model achieved:

- **Training Accuracy**: XX.XX%
- **Validation Accuracy**: XX.XX%
- **Test Accuracy**: XX.XX%

