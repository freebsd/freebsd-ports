# New ports collection makefile for:   kdelibs
# Version required:    1.0
# Date created:        28 October 1997
# Whom:                Stefan Eßer <se@freebsd.org>
#
# $Id: Makefile,v 1.25 1999/02/03 11:12:01 asami Exp $
#

DISTNAME=	kdelibs-1.1pre2
CATEGORIES=	x11 kde
MASTER_SITES=	$(MASTER_SITE_KDE)
MASTER_SITE_SUBDIR= stable/1.1pre2/distribution/tar/generic/source

MAINTAINER=	se@freebsd.org

LIB_DEPENDS=	gif.3:${PORTSDIR}/graphics/giflib \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.3:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff34

USE_QT=		yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	"--prefix=$(PREFIX)" \
		"--with-extra-includes=${PREFIX}/include" \
		"--x-inc=$(X11BASE)/include" \
		"--x-lib=$(X11BASE)/lib"
CONFIGURE_ENV=	CXXFLAGS="${CFLAGS}"
USE_GMAKE=	yes

.include <bsd.port.pre.mk>

post-install:
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib
.if ${PORTOBJFORMAT} == "aout"
	${LN} -sf libjscript.so.2.0   ${PREFIX}/lib/libjscript.so
	${LN} -sf libkab.so.2.0       ${PREFIX}/lib/libkab.so
	${LN} -sf libkdecore.so.2.0   ${PREFIX}/lib/libkdecore.so
	${LN} -sf libkdeui.so.2.0     ${PREFIX}/lib/libkdeui.so
	${LN} -sf libkfile.so.2.0     ${PREFIX}/lib/libkfile.so
	${LN} -sf libkfm.so.2.0       ${PREFIX}/lib/libkfm.so
	${LN} -sf libkhtmlw.so.2.0    ${PREFIX}/lib/libkhtmlw.so
	${LN} -sf libkimgio.so.2.0    ${PREFIX}/lib/libkimgio.so
	${LN} -sf libkspell.so.2.0    ${PREFIX}/lib/libkspell.so
	${LN} -sf libmediatool.so.2.0 ${PREFIX}/lib/libmediatool.so
.endif

.include <bsd.port.post.mk>
