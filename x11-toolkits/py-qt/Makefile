# New ports collection makefile for:	PyQt
# Date created:		Sun Oct 17 00:24:28 PDT 1999
# Whom:			adsharma@sharmas.dhs.org
#
# $FreeBSD$

PORTNAME=	py-qt
PORTVERSION=	2.2
CATEGORIES=	x11-toolkits python
MASTER_SITES=	http://www.river-bank.demon.co.uk/software/
DISTNAME=	PyQt-${PORTVERSION}

MAINTAINER=	adsharma@sharmas.dhs.org

LIB_DEPENDS=	sip.4:${PORTSDIR}/devel/sip

USE_QT_VER=	2
USE_PYTHON=	yes
USE_LIBTOOL=	yes
USE_GMAKE=	yes
CONFIGURE_ENV=	LDFLAGS=-lgcc \
		SIP_MOC="${X11BASE}/bin/moc2"

pre-patch:
	@find ${WRKSRC} -name Makefile.in | \
		xargs ${PERL} -pi -e 's|-lqt[^2]|-lqt2 |g'

post-configure:
	@${PERL} -pi -e 's|^deplibs_check_method=.*|deplibs_check_method=pass_all|' \
		${WRKSRC}/libtool

post-install:
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${PYTHON_SITELIBDIR}/eric

.include <bsd.port.mk>
