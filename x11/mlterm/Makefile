# New ports collection makefile for:	mlterm
# Date created:		9 December 2001
# Whom:			MANTANI Nobutaka <nobutaka@nobutaka.com>
#
# $FreeBSD$
#

PORTNAME=	mlterm
PORTVERSION=	2.6.2
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	nobutaka@FreeBSD.org

USE_X_PREFIX=	yes
USE_GNOMENG=	yes
USE_GNOME=	imlib
USE_LIBTOOL=	yes
USE_REINPLACE=	yes
CONFIGURE_ARGS=	--with-imagelib=imlib --enable-utmp
INSTALLS_SHLIB=	yes

MAN1=	mlterm.1 mlclient.1

.include <bsd.port.pre.mk>

.if ${XFREE86_VERSION} == 3
PKGNAMESUFFIX=	-noaa
.else
CONFIGURE_ARGS+=	--enable-anti-alias
.endif

post-configure:
	${REINPLACE_CMD} -e "s,%%PREFIX%%,${PREFIX}," \
		-e "s,%%PERL%%,${PERL}," \
		${WRKSRC}/tool/w3mmlconfig/Makefile

post-build:
	(cd ${WRKSRC}/tool/w3mmlconfig; ${MAKE})

post-install:
	(cd ${WRKSRC}/tool/w3mmlconfig; ${MAKE} install)
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/ja/mlterm
	${INSTALL_DATA} ${WRKSRC}/doc/ja/README.ja ${PREFIX}/share/doc/ja/mlterm
.endif

.include <bsd.port.post.mk>
