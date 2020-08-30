# Created by: Bruce M Simpson <bms@FreeBSD.org>
# $FreeBSD$

PORTNAME=	wmxss
PORTVERSION=	0.1
PORTREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	http://www.cs.mun.ca/~gstarkes/wmaker/dockapps/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Run xscreensaver modules inside a WindowMaker dock

# Fix build with -fno-common (llvm 11)
CFLAGS+=	-fcommon

DEPRECATED=	Unmaintained and dead upstream, does not build with -fno-common (llvm 11)
EXPIRATION_DATE=2021-04-01

USES=		uidfix xorg
USE_XORG=	x11 xpm
PLIST_FILES=	bin/wmxss
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/Src

post-extract:
	@( cd ${WRKSRC} ; ${MAKE} clean ; ${RM} .nfs* )

post-patch:
	@${REINPLACE_CMD} -E \
		-e 's|-O2||' \
		${BUILD_WRKSRC}/${MAKEFILE}

.include <bsd.port.mk>
