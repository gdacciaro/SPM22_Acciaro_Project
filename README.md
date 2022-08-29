## A parallelized version of the Jacobi Method

<div align="center">
 <p>
    <img style="" src="./logounipi.png" alt="Logo" width="250" >  <br>
    <p>
    Master Degree (Artificial Intelligence)<br>
    SPM course, Academic Year: 2021/2022, University of Pisa, Italy.
    </p>
  </p>
</div>
<div align="center">
 <p align="center"><h3>👨🏻‍💻 Author</h3>
    <a href="mailto:g.acciaro@studenti.unipi.it">Gennaro Daniele Acciaro</a>
  </p>
    <p align="center">
    <h3><a href="./report.pdf"> 📃 Report</a></h3>
  </p>
    <!-- <p align="center">
            <h3><a href="./slides.pdf">Slides</a></h3>
          </p>
        -->
</div>

## 🔍 Abstract
The Jacobi Method is an algorithm for finding the solution of a system of linear equations Ax = b. 
This C++ project aims to implement a sequential version of this algorithm, a parallelized version using native threads, and finally a parallel version with Fast Flow.

## 🔧 Setup
To make compilation and execution easier and faster, you can run the bash
script:

    ./run.sh

If necessary, you can still change any parameter by first compiling the program by running the command:
make and then:

    ./main.out <params>

where parameters are the following:

| parameter 	| domain 	| default value 	|
|---	|---	|---	|
| n 	| integer ≥ 0  	| 5000 	|
| num_of_worker 	| integer > 0 	| 100 	|
| num_of_iterations 	| integer > 0 	| 10 	|
| calculate_results 	| boolean (∈ {0, 1}) 	| 0 	|
| early_stopping 	| boolean (∈ {0, 1}) 	| 1 	|
| execute_unit_test 	| boolean (∈ {0, 1}) 	| 1 	|

### Main Files

    📦 
     ┣ 📂 calculate_results        
     ┣ 📂 setup                
     ┣ 📂 solutions            
     ┣ 📂 unit_test                    
     ┣ 📂 utils       
     ┗ 📜 main.cpp            