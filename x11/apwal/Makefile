PORTNAME=	apwal
PORTVERSION=	0.4.5
PORTREVISION=	16
CATEGORIES=	x11
MASTER_SITES=	http://apwal.free.fr/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple and powerful application launcher
WWW=		http://apwal.free.fr/

USE_GNOME=	gtk20 libxml2
USES=		gmake gnome pkgconfig

WRKSRC=		${WRKDIR}/${PORTNAME}/src

PLIST_FILES=	bin/apwal bin/apwal-editor

post-patch:
	@${CP} ${FILESDIR}/group_member.c ${WRKSRC}
	@${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|g' \
		${WRKSRC}/cereimg.c ${WRKSRC}/../example/apwalrc.xml

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/apwal ${STAGEDIR}${PREFIX}/bin
	${LN} -sf apwal ${STAGEDIR}${PREFIX}/bin/apwal-editor

.include <bsd.port.mk>
