!!! NEVER EVER INSTALL [XF86-VIDEO-INTEL](https://www.archlinux.org/packages/extra/x86_64/xf86-video-intel/) !!!
[<sup>O</sup>](https://www.reddit.com/r/archlinux/comments/6am55w/is_xf86videointel_still_needed/)
[<sup>O</sup>](https://askubuntu.com/questions/1200289/performance-issues-modesetting-vs-xf86-video-intel)
[<sup>O</sup>](https://forum.peppermintos.com/index.php?topic=7957.0)
[<sup>O</sup>](https://www.linuxquestions.org/questions/slackware-14/intel-recommended-x-driver-4175647103/)
<!--
[<sup>O</sup>]()
-->

See also [wayland](https://github.com/Un1Gfn/wayland)

---

* [Kernel Mode Setting](https://www.kernel.org/doc/html/latest/gpu/drm-kms.html)
  * [Archwiki](https://wiki.archlinux.org/index.php/Kernel_mode_setting)
  * [Wikipedia](https://en.wikipedia.org/wiki/Mode_setting)
* [i3](https://i3wm.org/)
  * [GitHub](https://github.com/i3/i3)
* [picom](https://github.com/yshui/picom)
  * [Archwiki](https://wiki.archlinux.org/index.php/Picom)

```
$ inxi -G
Graphics:  Device-1: Intel Mobile 4 Series Integrated Graphics driver: i915 v: kernel 
           Display: server: X.org 1.20.8 driver: i915 resolution: <xdpyinfo missing> 
           OpenGL: renderer: Mesa DRI Mobile Intel GM45 Express (CTG) v: 2.1 Mesa 20.0.4 

# lspci -k -nn -d 8086:2a43
00:02.1 Display controller [0380]: Intel Corporation Mobile 4 Series Chipset Integrated Graphics Controller [8086:2a43] (rev 07)
  Subsystem: Lenovo Mobile 4 Series Chipset Integrated Graphics Controller [17aa:20e4]

# lspci -k -nn -d 8086:2a42
00:02.0 VGA compatible controller [0300]: Intel Corporation Mobile 4 Series Chipset Integrated Graphics Controller [8086:2a42] (rev 07)
  Subsystem: Lenovo Mobile 4 Series Chipset Integrated Graphics Controller [17aa:20e4]
  Kernel driver in use: i915
  Kernel modules: i915
```





cp /etc/X11/xorg.conf.d/20-intel.conf.old _etc_X11_xorg.conf.d_20-intel.conf
