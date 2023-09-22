meter=input('distance you run：');
quan=floor(meter./400);
shengxia=400-(meter-quan.*400);
fprintf('%dlaps，%dmeters the next lap',quan,shengxia)