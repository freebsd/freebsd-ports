# ex:ts=8
# New ports collection makefile for:	xdialog
# Date created:			Jan 8, 2001
# Whom:				Ying-Chieh Liao <ijliao@csie.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	xdialog
PORTVERSION=	2.0.6
CATEGORIES=	x11
MASTER_SITES=	http://www.chez.com/godefroy/
DISTNAME=	${PORTNAME:S/x/X/}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.Org

USE_BZIP2=	yes
USE_GNOMENG=	yes
USE_GNOME=	gtk12
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=	Xdialog.1

DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
PLIST_DIRS=	DOCSDIR=${DOCSDIR}
PLIST_SUB+=	${PLIST_DIRS:S,DIR=${PREFIX}/,DIR=,}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.png ${DOCSDIR}
.endif

.include <bsd.port.mk>
