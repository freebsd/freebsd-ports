# New ports collection makefile for:	gmrun
# Date created:				26 September 2002
# Whom:					Adam Weinberger <adam@vectors.cx>
#
# $FreeBSD$
#

PORTNAME=	gmrun
PORTVERSION=	0.9.2
PORTREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A customizable program to run programs, with tab-completion

LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt

USE_GCC=	3.4
USE_X_PREFIX=	yes
USE_GNOME=	gtk20
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--disable-stlport

PORTDOCS=	README
PLIST_FILES=	bin/gmrun %%DATADIR%%/gmrunrc
PLIST_DIRS=	%%DATADIR%%

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
