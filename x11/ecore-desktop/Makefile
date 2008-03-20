# New ports collection makefile for:	ecore-desktop
# Date created:				22 September 2007
# Whom:					Stanislav Sedov <stas@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	desktop
PORTVERSION=	0.9.9.042
PORTREVISION=	0
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.springdaemons.com/pub/snapshots/e17/ \
		http://download.enlightenment.org/snapshots/2008-01-25/
PKGNAMEPREFIX=	ecore-
DISTNAME=	ecore-${PORTVERSION}

MAINTAINER=	stas@FreeBSD.org
COMMENT=	Enlightenment core abstraction library (desktop module)

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GNOME=	gnomehack pkgconfig gnometarget
USE_LDCONFIG=	yes
USE_EFL=	ecore
USE_EFL_ECORE=	file
BUILD_WRKSRC=	${WRKSRC}/src/lib/ecore_desktop
INSTALL_WRKSRC=	${BUILD_WRKSRC}

CONFIGURE_ARGS=	--disable-ecore-con \
		--disable-ecore-config \
		--enable-ecore-desktop \
		--disable-ecore-directfb \
		--disable-ecore-evas \
		--enable-ecore-file \
		--disable-ecore-ipc \
		--disable-ecore-job \
		--disable-ecore-sdl \
		--disable-ecore-txt \
		--disable-ecore-x \
		--disable-ecore-imf \
		--disable-ecore-imf_evas

post-patch:
	@${REINPLACE_CMD} -E \
		-e 's,\$$\(top_builddir\)/src/lib/ecore/\.libs,${LOCALBASE}/lib,'\
		-e 's,\$$\(top_builddir\)/src/lib/ecore_file/\.libs,${LOCALBASE}/lib,'\
		-e 's,\$$\(top_builddir\)/src/lib/ecore/libecore\.la,-lecore,'\
		-e 's,\$$\(top_builddir\)/src/lib/ecore_file/libecore_file\.la,-lecore_file,'\
		${BUILD_WRKSRC}/Makefile.in

post-install:
	${INSTALL_DATA} ${WRKSRC}/ecore-desktop.pc \
		${PREFIX}/libdata/pkgconfig/

.include <bsd.port.mk>
