#pragma once

template <typename T>
ALIGN16 const T FastSinOscillator<T>::mLUT[513] = { 1.00000000000000, 0.99987792968750, 0.99969482421875, 0.99926757812500, 0.99877929687500, 0.99810791015625, 0.99725341796875, 0.99627685546875, 0.99517822265625, 0.99389648437500, 0.99243164062500, 0.99084472656250, 0.98913574218750, 0.98724365234375, 0.98522949218750, 0.98309326171875, 0.98077392578125, 0.97827148437500, 0.97564697265625, 0.97290039062500, 0.96997070312500, 0.96691894531250, 0.96374511718750, 0.96038818359375, 0.95690917968750, 0.95324707031250, 0.94952392578125, 0.94555664062500, 0.94152832031250, 0.93731689453125, 0.93298339843750, 0.92846679687500, 0.92382812500000, 0.91906738281250, 0.91418457031250, 0.90911865234375, 0.90393066406250, 0.89862060546875, 0.89318847656250, 0.88763427734375, 0.88189697265625, 0.87603759765625, 0.87005615234375, 0.86395263671875, 0.85772705078125, 0.85131835937500, 0.84484863281250, 0.83819580078125, 0.83142089843750, 0.82458496093750, 0.81756591796875, 0.81042480468750, 0.80316162109375, 0.79577636718750, 0.78833007812500, 0.78070068359375, 0.77301025390625, 0.76513671875000, 0.75720214843750, 0.74908447265625, 0.74090576171875, 0.73260498046875, 0.72424316406250, 0.71569824218750, 0.70709228515625, 0.69836425781250, 0.68951416015625, 0.68054199218750, 0.67150878906250, 0.66241455078125, 0.65313720703125, 0.64379882812500, 0.63433837890625, 0.62481689453125, 0.61517333984375, 0.60546875000000, 0.59564208984375, 0.58575439453125, 0.57580566406250, 0.56567382812500, 0.55554199218750, 0.54528808593750, 0.53497314453125, 0.52453613281250, 0.51409912109375, 0.50347900390625, 0.49285888671875, 0.48217773437500, 0.47137451171875, 0.46051025390625, 0.44958496093750, 0.43859863281250, 0.42755126953125, 0.41638183593750, 0.40521240234375, 0.39398193359375, 0.38262939453125, 0.37127685546875, 0.35986328125000, 0.34838867187500, 0.33685302734375, 0.32525634765625, 0.31365966796875, 0.30200195312500, 0.29028320312500, 0.27850341796875, 0.26666259765625, 0.25482177734375, 0.24291992187500, 0.23101806640625, 0.21905517578125, 0.20709228515625, 0.19506835937500, 0.18298339843750, 0.17095947265625, 0.15881347656250, 0.14672851562500, 0.13452148437500, 0.12237548828125, 0.11016845703125, 0.09796142578125, 0.08575439453125, 0.07354736328125, 0.06127929687500, 0.04901123046875, 0.03680419921875, 0.02453613281250, 0.01226806640625, 0.00000000000000, -0.01226806640625, -0.02453613281250, -0.03680419921875, -0.04901123046875, -0.06127929687500, -0.07354736328125, -0.08575439453125, -0.09796142578125, -0.11016845703125, -0.12237548828125, -0.13452148437500, -0.14672851562500, -0.15881347656250, -0.17095947265625, -0.18298339843750, -0.19506835937500, -0.20709228515625, -0.21905517578125, -0.23101806640625, -0.24291992187500, -0.25482177734375, -0.26666259765625, -0.27850341796875, -0.29028320312500, -0.30200195312500, -0.31365966796875, -0.32525634765625, -0.33685302734375, -0.34838867187500, -0.35986328125000, -0.37127685546875, -0.38262939453125, -0.39398193359375, -0.40521240234375, -0.41638183593750, -0.42755126953125, -0.43859863281250, -0.44958496093750, -0.46051025390625, -0.47137451171875, -0.48217773437500, -0.49285888671875, -0.50347900390625, -0.51409912109375, -0.52453613281250, -0.53497314453125, -0.54528808593750, -0.55554199218750, -0.56567382812500, -0.57580566406250, -0.58575439453125, -0.59564208984375, -0.60546875000000, -0.61517333984375, -0.62481689453125, -0.63433837890625, -0.64379882812500, -0.65313720703125, -0.66241455078125, -0.67150878906250, -0.68054199218750, -0.68951416015625, -0.69836425781250, -0.70709228515625, -0.71569824218750, -0.72424316406250, -0.73260498046875, -0.74090576171875, -0.74908447265625, -0.75720214843750, -0.76513671875000, -0.77301025390625, -0.78070068359375, -0.78833007812500, -0.79577636718750, -0.80316162109375, -0.81042480468750, -0.81756591796875, -0.82458496093750, -0.83142089843750, -0.83819580078125, -0.84484863281250, -0.85131835937500, -0.85772705078125, -0.86395263671875, -0.87005615234375, -0.87603759765625, -0.88189697265625, -0.88763427734375, -0.89318847656250, -0.89862060546875, -0.90393066406250, -0.90911865234375, -0.91418457031250, -0.91906738281250, -0.92382812500000, -0.92846679687500, -0.93298339843750, -0.93731689453125, -0.94152832031250, -0.94555664062500, -0.94952392578125, -0.95324707031250, -0.95690917968750, -0.96038818359375, -0.96374511718750, -0.96691894531250, -0.96997070312500, -0.97290039062500, -0.97564697265625, -0.97827148437500, -0.98077392578125, -0.98309326171875, -0.98522949218750, -0.98724365234375, -0.98913574218750, -0.99084472656250, -0.99243164062500, -0.99389648437500, -0.99517822265625, -0.99627685546875, -0.99725341796875, -0.99810791015625, -0.99877929687500, -0.99926757812500, -0.99969482421875, -0.99987792968750, -1.00000000000000, -0.99987792968750, -0.99969482421875, -0.99926757812500, -0.99877929687500, -0.99810791015625, -0.99725341796875, -0.99627685546875, -0.99517822265625, -0.99389648437500, -0.99243164062500, -0.99084472656250, -0.98913574218750, -0.98724365234375, -0.98522949218750, -0.98309326171875, -0.98077392578125, -0.97827148437500, -0.97564697265625, -0.97290039062500, -0.96997070312500, -0.96691894531250, -0.96374511718750, -0.96038818359375, -0.95690917968750, -0.95324707031250, -0.94952392578125, -0.94555664062500, -0.94152832031250, -0.93731689453125, -0.93298339843750, -0.92846679687500, -0.92382812500000, -0.91906738281250, -0.91418457031250, -0.90911865234375, -0.90393066406250, -0.89862060546875, -0.89318847656250, -0.88763427734375, -0.88189697265625, -0.87603759765625, -0.87005615234375, -0.86395263671875, -0.85772705078125, -0.85131835937500, -0.84484863281250, -0.83819580078125, -0.83142089843750, -0.82458496093750, -0.81756591796875, -0.81042480468750, -0.80316162109375, -0.79577636718750, -0.78833007812500, -0.78070068359375, -0.77301025390625, -0.76513671875000, -0.75720214843750, -0.74908447265625, -0.74090576171875, -0.73260498046875, -0.72424316406250, -0.71569824218750, -0.70709228515625, -0.69836425781250, -0.68951416015625, -0.68054199218750, -0.67150878906250, -0.66241455078125, -0.65313720703125, -0.64379882812500, -0.63433837890625, -0.62481689453125, -0.61517333984375, -0.60546875000000, -0.59564208984375, -0.58575439453125, -0.57580566406250, -0.56567382812500, -0.55554199218750, -0.54528808593750, -0.53497314453125, -0.52453613281250, -0.51409912109375, -0.50347900390625, -0.49285888671875, -0.48217773437500, -0.47137451171875, -0.46051025390625, -0.44958496093750, -0.43859863281250, -0.42755126953125, -0.41638183593750, -0.40521240234375, -0.39398193359375, -0.38262939453125, -0.37127685546875, -0.35986328125000, -0.34838867187500, -0.33685302734375, -0.32525634765625, -0.31365966796875, -0.30200195312500, -0.29028320312500, -0.27850341796875, -0.26666259765625, -0.25482177734375, -0.24291992187500, -0.23101806640625, -0.21905517578125, -0.20709228515625, -0.19506835937500, -0.18298339843750, -0.17095947265625, -0.15881347656250, -0.14672851562500, -0.13452148437500, -0.12237548828125, -0.11016845703125, -0.09796142578125, -0.08575439453125, -0.07354736328125, -0.06127929687500, -0.04901123046875, -0.03680419921875, -0.02453613281250, -0.01226806640625, 0.00000000000000, 0.01226806640625, 0.02453613281250, 0.03680419921875, 0.04901123046875, 0.06127929687500, 0.07354736328125, 0.08575439453125, 0.09796142578125, 0.11016845703125, 0.12237548828125, 0.13452148437500, 0.14672851562500, 0.15881347656250, 0.17095947265625, 0.18298339843750, 0.19506835937500, 0.20709228515625, 0.21905517578125, 0.23101806640625, 0.24291992187500, 0.25482177734375, 0.26666259765625, 0.27850341796875, 0.29028320312500, 0.30200195312500, 0.31365966796875, 0.32525634765625, 0.33685302734375, 0.34838867187500, 0.35986328125000, 0.37127685546875, 0.38262939453125, 0.39398193359375, 0.40521240234375, 0.41638183593750, 0.42755126953125, 0.43859863281250, 0.44958496093750, 0.46051025390625, 0.47137451171875, 0.48217773437500, 0.49285888671875, 0.50347900390625, 0.51409912109375, 0.52453613281250, 0.53497314453125, 0.54528808593750, 0.55554199218750, 0.56567382812500, 0.57580566406250, 0.58575439453125, 0.59564208984375, 0.60546875000000, 0.61517333984375, 0.62481689453125, 0.63433837890625, 0.64379882812500, 0.65313720703125, 0.66241455078125, 0.67150878906250, 0.68054199218750, 0.68951416015625, 0.69836425781250, 0.70709228515625, 0.71569824218750, 0.72424316406250, 0.73260498046875, 0.74090576171875, 0.74908447265625, 0.75720214843750, 0.76513671875000, 0.77301025390625, 0.78070068359375, 0.78833007812500, 0.79577636718750, 0.80316162109375, 0.81042480468750, 0.81756591796875, 0.82458496093750, 0.83142089843750, 0.83819580078125, 0.84484863281250, 0.85131835937500, 0.85772705078125, 0.86395263671875, 0.87005615234375, 0.87603759765625, 0.88189697265625, 0.88763427734375, 0.89318847656250, 0.89862060546875, 0.90393066406250, 0.90911865234375, 0.91418457031250, 0.91906738281250, 0.92382812500000, 0.92846679687500, 0.93298339843750, 0.93731689453125, 0.94152832031250, 0.94555664062500, 0.94952392578125, 0.95324707031250, 0.95690917968750, 0.96038818359375, 0.96374511718750, 0.96691894531250, 0.96997070312500, 0.97290039062500, 0.97564697265625, 0.97827148437500, 0.98077392578125, 0.98309326171875, 0.98522949218750, 0.98724365234375, 0.98913574218750, 0.99084472656250, 0.99243164062500, 0.99389648437500, 0.99517822265625, 0.99627685546875, 0.99725341796875, 0.99810791015625, 0.99877929687500, 0.99926757812500, 0.99969482421875, 0.99987792968750, 1.00000000000000 };