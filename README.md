# RayTracingRender
基于SDL2的光线追踪渲染器
![demo1](http://p5kdl8q1n.bkt.clouddn.com/RayTracing.png)

这是一个用C++和SDL2写的光线追踪器，只需用一个画像素的API便可实现震撼的效果！该渲染器我会一直写下去，因为图形学太好玩了！
非常感谢Milo Yip大神的[教程](www.cnblogs.com/miloyip/archive/2010/03/29/1698953.html#!comments)，虚心向大神学习！

##依赖
* SDL2 仅需SDL2创建窗口，绘制上下文，以及设置像素颜色的API便可，SDL2的优点是跨平台，而且简单方便，你可以从[官方网站](https://www.libsdl.org/)下载，也可自行编译。


## 特点
* 支持球体、平面
* [Phong Model](http://en.wikipedia.org/wiki/Phong_reflection_model)
* 格子材质
* 多重反射

# 待研究方向
* 其他几何图形(长方体、柱体、三角形、曲面、高度场、等值面、……)
* 光源(方向光源、点光源、聚光灯、阴影、ambient occlusion)
* 材质(Phong-Blinn、Oren-Nayar、Torrance-Sparrow、折射、 Fresnel、BRDF、BSDF……) 
* 纹理(纹理座标、采样、Perlin noise)
* 摄影机模型(正投射、全景、景深) 
* 成像流程(渐进渲染、反锯齿、后期处理)
* 优化方法(场景剖分、低阶优化)
* 其他全局光照渲染方法