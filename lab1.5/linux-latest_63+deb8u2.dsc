-----BEGIN PGP SIGNED MESSAGE-----
Hash: SHA512

Format: 1.0
Source: linux-latest
Binary: linux-source, linux-doc, linux-tools, linux-image-alpha-generic, linux-headers-alpha-generic, linux-image-alpha-smp, linux-headers-alpha-smp, linux-image-amd64, linux-headers-amd64, linux-image-amd64-dbg, xen-linux-system-amd64, linux-image-arm64, linux-headers-arm64, linux-image-arm64-dbg, linux-image-ixp4xx, linux-headers-ixp4xx, linux-image-kirkwood, linux-headers-kirkwood, linux-image-orion5x, linux-headers-orion5x, linux-image-versatile, linux-headers-versatile, linux-image-armmp, linux-headers-armmp, linux-image-armmp-lpae, linux-headers-armmp-lpae, linux-image-parisc, linux-headers-parisc, linux-image-parisc64-smp, linux-headers-parisc64-smp, linux-image-586, linux-headers-586, linux-image-686-pae, linux-headers-686-pae, linux-image-686-pae-dbg, linux-image-itanium, linux-headers-itanium, linux-image-mckinley, linux-headers-mckinley, linux-image-m68k, linux-headers-m68k, linux-image-r4k-ip22, linux-headers-r4k-ip22, linux-image-r5k-ip32,
 linux-headers-r5k-ip32, linux-image-sb1-bcm91250a, linux-headers-sb1-bcm91250a, linux-image-4kc-malta, linux-headers-4kc-malta, linux-image-5kc-malta, linux-headers-5kc-malta, linux-image-octeon, linux-headers-octeon, linux-image-loongson-2e, linux-headers-loongson-2e, linux-image-loongson-2f, linux-headers-loongson-2f, linux-image-loongson-3, linux-headers-loongson-3, linux-image-powerpc, linux-headers-powerpc, linux-image-powerpc-smp, linux-headers-powerpc-smp, linux-image-powerpc64, linux-headers-powerpc64, linux-image-powerpcspe, linux-headers-powerpcspe, linux-image-powerpc64le, linux-headers-powerpc64le, linux-image-s390x, linux-headers-s390x, linux-image-s390x-dbg, linux-image-sh7751r, linux-headers-sh7751r, linux-image-sh7785lcr, linux-headers-sh7785lcr, linux-image-sparc64, linux-headers-sparc64, linux-image-sparc64-smp, linux-headers-sparc64-smp, linux-image-486,
 linux-headers-486
Architecture: all alpha amd64 i386 arm64 armel armhf hppa ia64 m68k mips mips64 mips64el mipsel powerpc ppc64 powerpcspe ppc64el s390 s390x sh4 sparc sparc64
Version: 63+deb8u2
Maintainer: Debian Kernel Team <debian-kernel@lists.debian.org>
Uploaders: Bastian Blank <waldi@debian.org>, Frederik Schüler <fs@debian.org>, Ben Hutchings <ben@decadent.org.uk>
Standards-Version: 3.9.5
Vcs-Browser: http://anonscm.debian.org/viewvc/kernel/dists/sid/linux-latest/
Vcs-Svn: svn://svn.debian.org/svn/kernel/dists/sid/linux-latest/
Build-Depends: debhelper (>> 7), linux-support-3.16.0-6
Package-List:
 linux-doc deb doc optional arch=all
 linux-headers-486 deb oldlibs optional arch=i386
 linux-headers-4kc-malta deb kernel optional arch=mips,mipsel
 linux-headers-586 deb kernel optional arch=i386
 linux-headers-5kc-malta deb kernel optional arch=mips,mips64,mips64el,mipsel
 linux-headers-686-pae deb kernel optional arch=i386
 linux-headers-alpha-generic deb kernel optional arch=alpha
 linux-headers-alpha-smp deb kernel optional arch=alpha
 linux-headers-amd64 deb kernel optional arch=amd64,i386
 linux-headers-arm64 deb kernel optional arch=arm64
 linux-headers-armmp deb kernel optional arch=armhf
 linux-headers-armmp-lpae deb kernel optional arch=armhf
 linux-headers-itanium deb kernel optional arch=ia64
 linux-headers-ixp4xx deb kernel optional arch=armel
 linux-headers-kirkwood deb kernel optional arch=armel
 linux-headers-loongson-2e deb kernel optional arch=mipsel
 linux-headers-loongson-2f deb kernel optional arch=mipsel
 linux-headers-loongson-3 deb kernel optional arch=mips64el,mipsel
 linux-headers-m68k deb kernel optional arch=m68k
 linux-headers-mckinley deb kernel optional arch=ia64
 linux-headers-octeon deb kernel optional arch=mips,mips64,mips64el
 linux-headers-orion5x deb kernel optional arch=armel
 linux-headers-parisc deb kernel optional arch=hppa
 linux-headers-parisc64-smp deb kernel optional arch=hppa
 linux-headers-powerpc deb kernel optional arch=powerpc
 linux-headers-powerpc-smp deb kernel optional arch=powerpc
 linux-headers-powerpc64 deb kernel optional arch=powerpc,ppc64
 linux-headers-powerpc64le deb kernel optional arch=ppc64el
 linux-headers-powerpcspe deb kernel optional arch=powerpcspe
 linux-headers-r4k-ip22 deb kernel optional arch=mips
 linux-headers-r5k-ip32 deb kernel optional arch=mips
 linux-headers-s390x deb kernel optional arch=s390,s390x
 linux-headers-sb1-bcm91250a deb kernel optional arch=mips,mips64,mips64el,mipsel
 linux-headers-sh7751r deb kernel optional arch=sh4
 linux-headers-sh7785lcr deb kernel optional arch=sh4
 linux-headers-sparc64 deb kernel optional arch=sparc,sparc64
 linux-headers-sparc64-smp deb kernel optional arch=sparc,sparc64
 linux-headers-versatile deb kernel optional arch=armel
 linux-image-486 deb oldlibs optional arch=i386
 linux-image-4kc-malta deb kernel optional arch=mips,mipsel
 linux-image-586 deb kernel optional arch=i386
 linux-image-5kc-malta deb kernel optional arch=mips,mips64,mips64el,mipsel
 linux-image-686-pae deb kernel optional arch=i386
 linux-image-686-pae-dbg deb kernel optional arch=i386
 linux-image-alpha-generic deb kernel optional arch=alpha
 linux-image-alpha-smp deb kernel optional arch=alpha
 linux-image-amd64 deb kernel optional arch=amd64,i386
 linux-image-amd64-dbg deb kernel optional arch=amd64
 linux-image-arm64 deb kernel optional arch=arm64
 linux-image-arm64-dbg deb kernel optional arch=arm64
 linux-image-armmp deb kernel optional arch=armhf
 linux-image-armmp-lpae deb kernel optional arch=armhf
 linux-image-itanium deb kernel optional arch=ia64
 linux-image-ixp4xx deb kernel optional arch=armel
 linux-image-kirkwood deb kernel optional arch=armel
 linux-image-loongson-2e deb kernel optional arch=mipsel
 linux-image-loongson-2f deb kernel optional arch=mipsel
 linux-image-loongson-3 deb kernel optional arch=mips64el,mipsel
 linux-image-m68k deb kernel optional arch=m68k
 linux-image-mckinley deb kernel optional arch=ia64
 linux-image-octeon deb kernel optional arch=mips,mips64,mips64el
 linux-image-orion5x deb kernel optional arch=armel
 linux-image-parisc deb kernel optional arch=hppa
 linux-image-parisc64-smp deb kernel optional arch=hppa
 linux-image-powerpc deb kernel optional arch=powerpc
 linux-image-powerpc-smp deb kernel optional arch=powerpc
 linux-image-powerpc64 deb kernel optional arch=powerpc,ppc64
 linux-image-powerpc64le deb kernel optional arch=ppc64el
 linux-image-powerpcspe deb kernel optional arch=powerpcspe
 linux-image-r4k-ip22 deb kernel optional arch=mips
 linux-image-r5k-ip32 deb kernel optional arch=mips
 linux-image-s390x deb kernel optional arch=s390,s390x
 linux-image-s390x-dbg deb kernel optional arch=s390,s390x
 linux-image-sb1-bcm91250a deb kernel optional arch=mips,mips64,mips64el,mipsel
 linux-image-sh7751r deb kernel optional arch=sh4
 linux-image-sh7785lcr deb kernel optional arch=sh4
 linux-image-sparc64 deb kernel optional arch=sparc,sparc64
 linux-image-sparc64-smp deb kernel optional arch=sparc,sparc64
 linux-image-versatile deb kernel optional arch=armel
 linux-source deb kernel optional arch=all
 linux-tools deb kernel optional arch=all
 xen-linux-system-amd64 deb kernel optional arch=amd64
Checksums-Sha1:
 ceeb33b50570b11d0a8ac8e064b9f224eaabdc1c 19247 linux-latest_63+deb8u2.tar.gz
Checksums-Sha256:
 b2388d0bbd241244f59cbe3cd64b3099d5f2e03e435a3d5ab8aac764747b55a9 19247 linux-latest_63+deb8u2.tar.gz
Files:
 0cd2026e7034bc97cfeedf72a7190983 19247 linux-latest_63+deb8u2.tar.gz

-----BEGIN PGP SIGNATURE-----

iQIzBAEBCgAdFiEErCspvTSmr92z9o8157/I7JWGEQkFAlrnNzAACgkQ57/I7JWG
EQlmOg/+P7G3FVE7k2u++SqNHNTpLY882FlCTkdbqX0HS/UZqEO6tJBVY5WwLYB5
O/VhkX+stFQHKrBEPOnDjP4kvEw9AgLiHO8A2G/2O6nsrVx2mj3n/YumRaqskyJm
lSCmkmVqdglMnGip3VhjUevDQl1x4Xm5JK3SX2FZjt1hgisBtcKhhONb469BuHvX
NTCEfirp/2yfrUN6ktFRLKzOHQsyWQ8AwYaq6MQRTjz6MrArMwX+gyXBB95lMBRz
YOjUwtSC7OcpNsyWER0baujZ/PjriSsVHDDhpykBMhaWtk4+llg32Bjzxciy7YIq
h+XskSN7oaRxyaQF/6Kex+ZdgPXxqFPN+o3mKE9kcd+RHgYEVjH2Ds1mvbs8C9Ej
J3N+oprkN4/9SBc7f90+6boWgs2TTOBmNthavc8hRCagndoyze8bLe3IGrGfJnTh
eAk9sKrKjcrpATG0I3tdajXUQLBKhFTJpEHgxRG8ExpjqL4uBleZfn2OO+dePPum
NDZLnyGfjOvXvOxOpzvs2DeOLliFqF8Z5xnvn44DxOLqAoTNIPZi2yjeBqtGCcUM
GUiE/RHQCbVUcbi0c8ahndOPbT7tp8jKh2f4ao4XEwmER+KguyH9AzD573Pzd1im
0S5DnRRYIde+Ex10lHFDnzFKtLqVg2TNhtK/oKTfWrv6DgvpdVw=
=w4sX
-----END PGP SIGNATURE-----
