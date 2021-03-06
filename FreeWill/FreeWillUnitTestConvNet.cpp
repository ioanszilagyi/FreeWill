#include "FreeWillUnitTest.h"
#include "Operator/Convolution.h"
#include "Operator/ConvolutionDerivative.h"
#include "Operator/Activation.h"
#include "Operator/CrossEntropyLoss.h"
#include "Operator/SigmoidCrossEntropyLossDerivative.h"
#include "Operator/ActivationDerivative.h"


void FreeWillUnitTest::convolutionTest()
{
    FreeWill::Tensor<FreeWill::DeviceType::CPU_NAIVE, float> input({3,5,5,1});
    input.init();
    
    
    FreeWill::Tensor<FreeWill::DeviceType::CPU_NAIVE, float> featureMaps({3,3,3,2});
    featureMaps.init();
    

    FreeWill::Tensor<FreeWill::DeviceType::CPU_NAIVE, float> output({2,3,3,1});
    output.init();

    FreeWill::Tensor<FreeWill::DeviceType::CPU_NAIVE, float> bias({2});
    bias.init();


    FreeWill::Convolution<FreeWill::DeviceType::CPU_NAIVE, float> convolution(2,2,1,1);
    convolution.setInputParameter("Input", &input);
    convolution.setInputParameter("FeatureMap", &featureMaps);
    convolution.setInputParameter("Bias", &bias);
    convolution.setOutputParameter("Output", &output);

    QVERIFY(convolution.init());


    /*float r[] = {1,2,1,1,2,
                 0,1,0,2,1,
                 2,2,2,2,0,
                 2,1,2,1,2,
                 0,1,2,0,1};

    float g[] = {0,0,1,2,1,
                 0,2,2,1,2,
                 0,0,0,0,2,
                 1,0,0,0,1,
                 2,2,2,0,1};

    float b[] = {0,2,0,2,2,
                 2,2,2,0,1,
                 1,0,2,1,1,
                 0,1,1,0,2,
                 0,2,1,1,2};
*/
/*    for(int i = 0;i<25;++i)
    {
        printf("%f,%f,%f,\n", r[i], g[i], b[i]);
    }
*/
    float inputArray[] = {
        1.000000,0.000000,0.000000,
        2.000000,0.000000,2.000000,
        1.000000,1.000000,0.000000,
        1.000000,2.000000,2.000000,
        2.000000,1.000000,2.000000,
        0.000000,0.000000,2.000000,
        1.000000,2.000000,2.000000,
        0.000000,2.000000,2.000000,
        2.000000,1.000000,0.000000,
        1.000000,2.000000,1.000000,
        2.000000,0.000000,1.000000,
        2.000000,0.000000,0.000000,
        2.000000,0.000000,2.000000,
        2.000000,0.000000,1.000000,
        0.000000,2.000000,1.000000,
        2.000000,1.000000,0.000000,
        1.000000,0.000000,1.000000,
        2.000000,0.000000,1.000000,
        1.000000,0.000000,0.000000,
        2.000000,1.000000,2.000000,
        0.000000,2.000000,0.000000,
        1.000000,2.000000,2.000000,
        2.000000,2.000000,1.000000,
        0.000000,0.000000,1.000000,
        1.000000,1.000000,2.000000
    };

/*    float f11[] = {0,-1,1,
                 1,0,-1,
                 1,1,-1};

    float f12[] = {1,1,-1,
                  0,0,-1,
                  -1,-1,-1};

    float f13[] = {1,1,0,
                   1,1,1,
                   0,-1,1};

    float f21[] = {0,-1,1,
                  1,0,0,
                  1,1,1};

    float f22[] = {1,0,1,
                  -1,-1,-1,
                  1,1,1};

    float f23[] = {0,-1,1,
                  0,-1,1,
                  1,-1,0};
                  */
/*
    for(int i =0;i<9;++i)
    {

        printf("%f,%f,%f,\n", f11[i], f12[i], f13[i]);
    }

    for(int i =0;i<9;++i)
    {

        printf("%f,%f,%f,\n", f21[i], f22[i], f23[i]);
    }
*/
    float featureMapArray[] = {
        0.000000,1.000000,1.000000,
        -1.000000,1.000000,1.000000,
        1.000000,-1.000000,0.000000,
        1.000000,0.000000,1.000000,
        0.000000,0.000000,1.000000,
        -1.000000,-1.000000,1.000000,
        1.000000,-1.000000,0.000000,
        1.000000,-1.000000,-1.000000,
        -1.000000,-1.000000,1.000000,
        0.000000,1.000000,0.000000,
        -1.000000,0.000000,-1.000000,
        1.000000,1.000000,1.000000,
        1.000000,-1.000000,0.000000,
        0.000000,-1.000000,-1.000000,
        0.000000,-1.000000,1.000000,
        1.000000,1.000000,1.000000,
        1.000000,1.000000,-1.000000,
        1.000000,1.000000,0.000000
    };

    float biasArray[] = {1,0};

    unsigned int inputSize = input.shape().size();
    for(unsigned int i = 0; i< inputSize;++i)
    {
        input[i] = inputArray[i];
    }

    unsigned int featureMapsSize = featureMaps.shape().size();
    for(unsigned int i = 0; i< featureMapsSize;++i)
    {
        featureMaps[i] = featureMapArray[i];
    }

    unsigned int biasSize = bias.shape().size();
    for(unsigned int i = 0; i<biasSize;++i)
    {
        bias[i] = biasArray[i];
    }

    convolution.evaluate();

    /*
    float output1[] = {-2,-4,5,
                      2,14,8,
                      0,7,5};

    float output2[] = {3,9,1,
                      6,8,0,
                      -2,-5,-7};
*/
    /*for (int i =0;i<9;++i)
    {

        printf("%f,%f,\n", output1[i], output2[i]);
    }*/

    float outputArray[] = {
        -2.000000,3.000000,
        -4.000000,9.000000,
        5.000000,1.000000,
        2.000000,6.000000,
        14.000000,8.000000,
        8.000000,0.000000,
        0.000000,-2.000000,
        7.000000,-5.000000,
        5.000000,-7.000000
    };

    unsigned int outputSize = output.shape().size();

    for(unsigned int i =0;i<outputSize;++i)
    {
        //qDebug() <<"output -"<< outputArray[i]<<";" << output[i];
        QVERIFY(outputArray[i] == output[i]);
    }

}

void FreeWillUnitTest::convolutionTestGPU()
{
    FreeWill::Tensor<FreeWill::DeviceType::GPU_CUDA, float> input({3,5,5,1});
    input.init();


    FreeWill::Tensor<FreeWill::DeviceType::GPU_CUDA, float> featureMaps({3,3,3,2});
    featureMaps.init();


    FreeWill::Tensor<FreeWill::DeviceType::GPU_CUDA, float> output({2,3,3,1});
    output.init();

    FreeWill::Tensor<FreeWill::DeviceType::GPU_CUDA, float> bias({2});
    bias.init();


    FreeWill::Convolution<FreeWill::DeviceType::GPU_CUDA, float> convolution(2,2,1,1);
    convolution.setInputParameter("Input", &input);
    convolution.setInputParameter("FeatureMap", &featureMaps);
    convolution.setInputParameter("Bias", &bias);
    convolution.setOutputParameter("Output", &output);

    QVERIFY(convolution.init());

    float inputArray[] = {
        1.000000,0.000000,0.000000,
        2.000000,0.000000,2.000000,
        1.000000,1.000000,0.000000,
        1.000000,2.000000,2.000000,
        2.000000,1.000000,2.000000,
        0.000000,0.000000,2.000000,
        1.000000,2.000000,2.000000,
        0.000000,2.000000,2.000000,
        2.000000,1.000000,0.000000,
        1.000000,2.000000,1.000000,
        2.000000,0.000000,1.000000,
        2.000000,0.000000,0.000000,
        2.000000,0.000000,2.000000,
        2.000000,0.000000,1.000000,
        0.000000,2.000000,1.000000,
        2.000000,1.000000,0.000000,
        1.000000,0.000000,1.000000,
        2.000000,0.000000,1.000000,
        1.000000,0.000000,0.000000,
        2.000000,1.000000,2.000000,
        0.000000,2.000000,0.000000,
        1.000000,2.000000,2.000000,
        2.000000,2.000000,1.000000,
        0.000000,0.000000,1.000000,
        1.000000,1.000000,2.000000
    };

    float featureMapArray[] = {
        0.000000,1.000000,1.000000,
        -1.000000,1.000000,1.000000,
        1.000000,-1.000000,0.000000,
        1.000000,0.000000,1.000000,
        0.000000,0.000000,1.000000,
        -1.000000,-1.000000,1.000000,
        1.000000,-1.000000,0.000000,
        1.000000,-1.000000,-1.000000,
        -1.000000,-1.000000,1.000000,
        0.000000,1.000000,0.000000,
        -1.000000,0.000000,-1.000000,
        1.000000,1.000000,1.000000,
        1.000000,-1.000000,0.000000,
        0.000000,-1.000000,-1.000000,
        0.000000,-1.000000,1.000000,
        1.000000,1.000000,1.000000,
        1.000000,1.000000,-1.000000,
        1.000000,1.000000,0.000000
    };

    float biasArray[] = {1,0};

    unsigned int inputSize = input.shape().size();
    for(unsigned int i = 0; i< inputSize;++i)
    {
        input[i] = inputArray[i];
    }

    unsigned int featureMapsSize = featureMaps.shape().size();
    for(unsigned int i = 0; i< featureMapsSize;++i)
    {
        featureMaps[i] = featureMapArray[i];
    }

    unsigned int biasSize = bias.shape().size();
    for(unsigned int i = 0; i<biasSize;++i)
    {
        bias[i] = biasArray[i];
    }

    input.copyFromHostToDevice();
    featureMaps.copyFromHostToDevice();
    bias.copyFromHostToDevice();

    convolution.evaluate();


    float outputArray[] = {
        -2.000000,3.000000,
        -4.000000,9.000000,
        5.000000,1.000000,
        2.000000,6.000000,
        14.000000,8.000000,
        8.000000,0.000000,
        0.000000,-2.000000,
        7.000000,-5.000000,
        5.000000,-7.000000
    };

    output.copyFromDeviceToHost();
    unsigned int outputSize = output.shape().size();

    for(unsigned int i =0;i<outputSize;++i)
    {
        //qDebug() <<"output -"<< outputArray[i]<<";" << output[i];
        QVERIFY(outputArray[i] == output[i]);
    }

}

void FreeWillUnitTest::convolutionDerivativeTest()
{
    FreeWill::Tensor<FreeWill::DeviceType::CPU_NAIVE, double> prevActivaion({3,5,5,1});
    prevActivaion.init();
    
    
    FreeWill::Tensor<FreeWill::DeviceType::CPU_NAIVE, double> featureMaps({3,3,3,2});
    featureMaps.init();
    

    FreeWill::Tensor<FreeWill::DeviceType::CPU_NAIVE, double> outputGrad({2,3,3,1});
    outputGrad.init();

    FreeWill::Tensor<FreeWill::DeviceType::CPU_NAIVE, double> inputGrad({3,5,5,1});
    inputGrad.init();

    FreeWill::Tensor<FreeWill::DeviceType::CPU_NAIVE, double> featureMapGrad({3,3,3,2});
    featureMapGrad.init();

    FreeWill::Tensor<FreeWill::DeviceType::CPU_NAIVE, double> fakeFeatureMapGrad({3,3,3,2});
    fakeFeatureMapGrad.init();

    FreeWill::Tensor<FreeWill::DeviceType::CPU_NAIVE, double> biasGrad({2});
    biasGrad.init();


    FreeWill::ConvolutionDerivative<FreeWill::DeviceType::CPU_NAIVE, double> convolutionDerivative(2,2,1,1);
    convolutionDerivative.setInputParameter("PrevActivation", &prevActivaion);
    convolutionDerivative.setInputParameter("FeatureMap", &featureMaps);
    convolutionDerivative.setInputParameter("OutputGrad", &outputGrad);

    convolutionDerivative.setOutputParameter("InputGrad", &inputGrad);
    convolutionDerivative.setOutputParameter("FeatureMapGrad", &featureMapGrad);
    convolutionDerivative.setOutputParameter("BiasGrad", &biasGrad);

    QVERIFY(convolutionDerivative.init());

    double inputArray[] = {
            0,1,1, 0,1,1, 2,1,0, 0,1,2, 2,0,2,
            0,1,0,1,0,0,2,0,0,0,0,0,0,1,1,
            0,0,0,0,0,1,2,1,1,2,0,1,1,0,0,
            1,1,1,0,2,0,0,0,2,2,2,0,0,2,1,
            0,1,0,0,0,2,0,1,0,2,2,1,2,0,1
    };

    double featureMapArray[] = {
            0,0,1,-1,1,0,1,1,1,
            0,0,-1,1,-1,-1,0,1,-1,
            0,1,-1,-1,1,0,-1,0,-1,
            
            1,0,-1, 1,0,1, 1,-1,0,
            1,0,-1, 0,0,1, -1,0,1,
            -1,1,-1, -1,0,0, 1,1,-1
    };

    double biasArray[] = {1,0};

    FreeWill::Tensor<FreeWill::DeviceType::CPU_NAIVE, double> input({3,5,5,1});
    input.init();

    FreeWill::Tensor<FreeWill::DeviceType::CPU_NAIVE, double> bias({2});
    bias.init();

    FreeWill::Tensor<FreeWill::DeviceType::CPU_NAIVE, double> output({2,3,3,1});
    output.init();
    
    unsigned int inputSize = input.shape().size();
    for(unsigned int i = 0;i<inputSize;++i)
    {
        prevActivaion[i] = input[i] = inputArray[i];
    }
   
    unsigned int featureMapSize = featureMaps.shape().size();
    for(unsigned int i =0;i<featureMapSize;++i)
    {
        featureMaps[i] = featureMapArray[i];
    }

    unsigned int biasSize = bias.shape().size();
    for(unsigned int i = 0;i<biasSize;++i)
    {
        bias[i] = biasArray[i];
    }

    FreeWill::Convolution<FreeWill::DeviceType::CPU_NAIVE, double> convolution(2,2,1,1);
    convolution.setInputParameter("Input", &input);
    convolution.setInputParameter("FeatureMap", &featureMaps);
    convolution.setInputParameter("Bias", &bias);

    convolution.setOutputParameter("Output", &output);
  
    QVERIFY(convolution.init());

    FreeWill::Activation<FreeWill::ActivationMode::SIGMOID, FreeWill::DeviceType::CPU_NAIVE, double> sigmoid;
    sigmoid.setInputParameter("Input", &output);
    sigmoid.setOutputParameter("Output", &output);

    QVERIFY(sigmoid.init());

    FreeWill::Tensor<FreeWill::DeviceType::CPU_NAIVE, double> flatOutput({output.shape().size(), 1});
    flatOutput.init();

    

    unsigned int outputSize = output.shape().size();
    
    FreeWill::Tensor<FreeWill::DeviceType::CPU_NAIVE, double> label({outputSize, 1});
    label.init();
    label.randomize();

    FreeWill::Tensor<FreeWill::DeviceType::CPU_NAIVE, double> cost({1,1});
    cost.init();

    FreeWill::CrossEntropyLoss<FreeWill::DeviceType::CPU_NAIVE, double> crossEntropyLoss;
    crossEntropyLoss.setInputParameter("Input", &flatOutput);
    crossEntropyLoss.setInputParameter("Label", &label);
    crossEntropyLoss.setOutputParameter("Cost", &cost);

    QVERIFY(crossEntropyLoss.init());

    for(unsigned int i = 0;i<featureMapSize;++i)
    {
        output.clear();
        flatOutput.clear();
        cost.clear();

        double origin = featureMaps[i];

        double cost_big = 0;

        featureMaps[i] = origin + epsilon;

        convolution.evaluate();

        sigmoid.evaluate();

        for(unsigned int e = 0;e<outputSize;++e)
        {
            flatOutput[e] = output[e];
       //     printf("\n %f", flatOutput[e]);
        }

        crossEntropyLoss.evaluate();

        cost_big = cost[0];


        output.clear();
        flatOutput.clear();
        cost.clear();

        double cost_small = 0;

        featureMaps[i] = origin - epsilon;

        convolution.evaluate();

        sigmoid.evaluate();

        for(unsigned int e=0;e<outputSize;++e)
        {
            flatOutput[e] = output[e];
         //   printf(", %f\n", flatOutput[e] );
        }

        crossEntropyLoss.evaluate();

        cost_small = cost[0];

       // qDebug() << "cost big" << cost_big << "cost small" << cost_small;

        double fakeGrad = (cost_big - cost_small) / (2.0*epsilon);

        fakeFeatureMapGrad[i] = fakeGrad;

        featureMaps[i] = origin;

       // return;
    }

    output.clear();
    flatOutput.clear();
    cost.clear();

    convolution.evaluate();
    sigmoid.evaluate();

    for(unsigned int e = 0;e<outputSize;++e)
    {
        flatOutput[e] = output[e];
    }

    crossEntropyLoss.evaluate();

    FreeWill::Tensor<FreeWill::DeviceType::CPU_NAIVE, double> flatOuputGrad({outputSize,1});
    flatOuputGrad.init();

    FreeWill::SigmoidCrossEntropyLossDerivative<FreeWill::DeviceType::CPU_NAIVE, double> sigmoidCrossEntropyLossDerivative;
    sigmoidCrossEntropyLossDerivative.setInputParameter("Input", &flatOutput);
    sigmoidCrossEntropyLossDerivative.setInputParameter("Label", &label);
    sigmoidCrossEntropyLossDerivative.setOutputParameter("Output", &flatOuputGrad);

    QVERIFY(sigmoidCrossEntropyLossDerivative.init());

    sigmoidCrossEntropyLossDerivative.evaluate();

    for(unsigned int e = 0;e<outputSize;++e)
    {
        outputGrad[e] = flatOuputGrad[e];
    }

    convolutionDerivative.evaluate();

   for(unsigned int i = 0;i<featureMapSize;++i)
   {
     //qDebug() << "fake" << fakeFeatureMapGrad[i] << "real" << featureMapGrad[i];
   
     //qDebug()<< "diff" << std::abs(fakeFeatureMapGrad[i] - featureMapGrad[i]);
     
     QVERIFY(relativeError(fakeFeatureMapGrad[i], featureMapGrad[i]) < epsilon);
   } 
}

void FreeWillUnitTest::convolutionDerivativeTestGPU()
{
    FreeWill::Tensor<FreeWill::DeviceType::GPU_CUDA, float> prevActivaion({3,5,5,1});
    prevActivaion.init();
    prevActivaion.randomize();

    FreeWill::Tensor<FreeWill::DeviceType::GPU_CUDA, float> featureMaps({3,3,3,2});
    featureMaps.init();
    featureMaps.randomize();

    FreeWill::Tensor<FreeWill::DeviceType::GPU_CUDA, float> outputGrad({2,3,3,1});
    outputGrad.init();
    outputGrad.randomize();

    FreeWill::Tensor<FreeWill::DeviceType::GPU_CUDA, float> inputGrad({3,5,5,1});
    inputGrad.init();

    FreeWill::Tensor<FreeWill::DeviceType::GPU_CUDA, float> featureMapGrad({3,3,3,2});
    featureMapGrad.init();
    

    FreeWill::Tensor<FreeWill::DeviceType::GPU_CUDA, float> fakeFeatureMapGrad({3,3,3,2});
    fakeFeatureMapGrad.init();

    FreeWill::Tensor<FreeWill::DeviceType::GPU_CUDA, float> biasGrad({2});
    biasGrad.init();


    FreeWill::ConvolutionDerivative<FreeWill::DeviceType::GPU_CUDA, float> convolutionDerivative(2,2,1,1);
    convolutionDerivative.setInputParameter("PrevActivation", &prevActivaion);
    convolutionDerivative.setInputParameter("FeatureMap", &featureMaps);
    convolutionDerivative.setInputParameter("OutputGrad", &outputGrad);

    convolutionDerivative.setOutputParameter("InputGrad", &inputGrad);
    convolutionDerivative.setOutputParameter("FeatureMapGrad", &featureMapGrad);
    convolutionDerivative.setOutputParameter("BiasGrad", &biasGrad);

    QVERIFY(convolutionDerivative.init());

    prevActivaion.copyFromHostToDevice();
    featureMaps.copyFromHostToDevice();
    outputGrad.copyFromHostToDevice();

    FreeWill::Tensor<FreeWill::DeviceType::CPU_NAIVE, float> prevActivaionCPU({3,5,5,1});
    prevActivaionCPU.init();

    for (unsigned int i = 0;i<prevActivaion.shape().size();++i)
    {
        prevActivaionCPU[i] = prevActivaion[i];
    }

    FreeWill::Tensor<FreeWill::DeviceType::CPU_NAIVE, float> featureMapsCPU({3,3,3,2});
    featureMapsCPU.init();

    for (unsigned int i = 0; i<featureMapsCPU.shape().size();++i)
    {
        featureMapsCPU[i] = featureMaps[i];
    }

    FreeWill::Tensor<FreeWill::DeviceType::CPU_NAIVE, float> outputGradCPU({2,3,3,1});
    outputGradCPU.init();

    for (unsigned int i =0;i<outputGradCPU.shape().size() ;++i)
    {
        outputGradCPU[i] = outputGrad[i];
    }

    FreeWill::Tensor<FreeWill::DeviceType::CPU_NAIVE, float> inputGradCPU({3,5,5,1});
    inputGradCPU.init();

    FreeWill::Tensor<FreeWill::DeviceType::CPU_NAIVE, float> featureMapGradCPU({3,3,3,2});
    featureMapGradCPU.init();
    

    FreeWill::Tensor<FreeWill::DeviceType::CPU_NAIVE, float> fakeFeatureMapGradCPU({3,3,3,2});
    fakeFeatureMapGradCPU.init();

    FreeWill::Tensor<FreeWill::DeviceType::CPU_NAIVE, float> biasGradCPU({2});
    biasGradCPU.init();


    FreeWill::ConvolutionDerivative<FreeWill::DeviceType::CPU_NAIVE, float> convolutionDerivativeCPU(2,2,1,1);
    convolutionDerivativeCPU.setInputParameter("PrevActivation", &prevActivaionCPU);
    convolutionDerivativeCPU.setInputParameter("FeatureMap", &featureMapsCPU);
    convolutionDerivativeCPU.setInputParameter("OutputGrad", &outputGradCPU);

    convolutionDerivativeCPU.setOutputParameter("InputGrad", &inputGradCPU);
    convolutionDerivativeCPU.setOutputParameter("FeatureMapGrad", &featureMapGradCPU);
    convolutionDerivativeCPU.setOutputParameter("BiasGrad", &biasGradCPU);

    QVERIFY(convolutionDerivativeCPU.init());

    
    convolutionDerivative.evaluate();
    convolutionDerivativeCPU.evaluate();

    featureMapGrad.copyFromDeviceToHost();
    biasGrad.copyFromDeviceToHost();
    inputGrad.copyFromDeviceToHost();    
//    qDebug() << "feature map grad:";

    for(unsigned int i=0;i<featureMapGrad.shape().size();++i)
    {
        QVERIFY(std::abs(featureMapGrad[i] - featureMapGradCPU[i]) < epsilon);
//        qDebug() << featureMapGrad[i] << featureMapGradCPU[i];
    }

//    qDebug() << "bias grad:";
    for(unsigned int i=0;i<biasGrad.shape().size();++i)
    {
//        qDebug() << biasGrad[i] << biasGradCPU[i];
        QVERIFY(std::abs(biasGrad[i] - biasGradCPU[i]) < epsilon);
    }


  //  qDebug() << "PrevActivation grad:";

    for (unsigned int i =0;i<inputGrad.shape().size();++i)
    {
//        qDebug() << inputGrad[i] << inputGradCPU[i];
        QVERIFY(std::abs(inputGrad[i] - inputGradCPU[i]) < epsilon);
    }
}
