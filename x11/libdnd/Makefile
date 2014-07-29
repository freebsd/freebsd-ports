# Created by: lukin@okbmei.msk.su
# $FreeBSD$

PORTNAME=	libdnd
PORTVERSION=	1.1
PORTREVISION=	4
CATEGORIES=	x11
MASTER_SITES=	http://leb.net/offix/
DISTNAME=	dnd.${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Drag and drop library

USES=		tar:tgz
USE_XORG=	x11 xmu ice xaw
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/DND/DNDlib
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include/
LDFLAGS+=	-L${LOCALBASE}/lib/
MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKDIR}/DND/DNDdoc/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
