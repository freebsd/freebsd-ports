# New ports collection makefile for:   vdk
# Date created:        30 January 2000
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	vdk
PORTVERSION=	2.4.1
PORTREVISION=	5
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	vdklib

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ wrapper for GTK+ toolkit

USE_AUTOTOOLS=	libtool:22
USE_GNOME=	gnomehack gnometarget gtk20
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--enable-opt=no --enable-doc-html=no --enable-testvdk=no
USE_LDCONFIG=	yes

MAN1=		vdk-config-2.1

CPPFLAGS=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib -lgnuregex ${PTHREAD_LIBS}

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e \
		's|CXXFLAGS="-s"|CXXFLAGS="$$CXXFLAGS"|g' ${WRKSRC}/configure
.for file in vdk-config-2.in vdk-2.x.pc.in
	@${REINPLACE_CMD} -e 's|-lpthread|${LDFLAGS}|g' ${WRKSRC}/${file}
.endfor
.for file in vdk/FileDialog.h vdk/gtksourcebuffer.h vdk/gtksourcetag.h
	@${REINPLACE_CMD} -e 's|<regex\.h>|<gnu/regex.h>|g' ${WRKSRC}/${file}
.endfor
	@${REINPLACE_CMD} -e \
		's|VDKComboEntry::||g' ${WRKSRC}/vdk/vdkcomboentry.h
	@${REINPLACE_CMD} -e \
		's|VDKFileChooser::||g' ${WRKSRC}/vdk/vdkfilechooser.h

.include <bsd.port.post.mk>
