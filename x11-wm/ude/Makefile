# New ports collection makefile for:	ude
# Date created:		06 Mar 2000
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	ude
PORTVERSION=	0.2.9b
CATEGORIES=	x11-wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	udeproject

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small, fast, compact windowmanager

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg

USE_X_PREFIX=	yes
USE_XPM=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

post-patch:
	@${REINPLACE_CMD} -e  's|(getc(|(fgetc(|g' ${WRKSRC}/uwm/special.c

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/html
	${INSTALL_DATA} ${WRKSRC}/doc/html/*.css ${DOCSDIR}/html
	${INSTALL_DATA} ${WRKSRC}/doc/html/*.html ${DOCSDIR}/html
.endif

.include <bsd.port.mk>
