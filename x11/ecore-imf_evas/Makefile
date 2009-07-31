# New ports collection makefile for:	ecore-emf_evas
# Date created:				17 September 2007
# Whom:					Stanislav Sedov <stas@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	imf_evas
PORTVERSION=	0.9.9.042
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.springdaemons.com/pub/snapshots/e17/ \
		http://download.enlightenment.org/snapshots/2008-01-25/
PKGNAMEPREFIX=	ecore-
DISTNAME=	ecore-${PORTVERSION}

MAINTAINER=	stas@FreeBSD.org
COMMENT=	Enlightenment core abstraction library (IMF-Evas module)

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GNOME=	gnomehack pkgconfig gnometarget
USE_LDCONFIG=	yes
USE_EFL=	ecore evas
USE_EFL_ECORE=	imf
BUILD_WRKSRC=	${WRKSRC}/src/lib/ecore_imf_evas
INSTALL_WRKSRC=	${BUILD_WRKSRC}

CONFIGURE_ARGS=	--enable-ecore-con \
		--enable-ecore-config \
		--disable-ecore-desktop \
		--disable-ecore-directfb \
		--disable-ecore-evas \
		--disable-ecore-file \
		--enable-ecore-ipc \
		--disable-ecore-job \
		--disable-ecore-sdl \
		--disable-ecore-txt \
		--disable-ecore-x \
		--enable-ecore-imf \
		--enable-ecore-imf_evas

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -E \
		-e 's,\$$\(top_builddir\)/src/lib/ecore/\.libs,${LOCALBASE}/lib,'\
		-e 's,\$$\(top_builddir\)/src/lib/ecore_imf/\.libs,${LOCALBASE}/lib,'\
		-e 's,\$$\(top_builddir\)/src/lib/ecore/libecore\.la,-lecore,'\
		-e 's,\$$\(top_builddir\)/src/lib/ecore_imf/libecore_imf\.la,-lecore_imf,'\
		${BUILD_WRKSRC}/Makefile.in

post-install:
	${INSTALL_DATA} ${WRKSRC}/ecore-imf-evas.pc \
		${PREFIX}/libdata/pkgconfig/

.include <bsd.port.post.mk>
