# New ports collection makefile for:	kwix
# Date created:				30 March 2001
# Whom:					Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kwix
PORTVERSION=	1.0.9
CATEGORIES=	x11-wm kde
MASTER_SITES=	ftp://ftp.kde.com/pub/Art_Music/Themes/KwiX/ \
		ftp://ftp.thekompany.com/pub/kwix/
DISTNAME=	${PORTNAME}-${PORTVERSION}kb

MAINTAINER=	demon@FreeBSD.org

LIB_DEPENDS=	intl.1:${PORTSDIR}/devel/gettext

USE_KDEBASE_VER=2
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

post-patch:
	@${PERL} -pi -e 's#lqt#lqt2#g' ${WRKSRC}/configure

.include <bsd.port.mk>
